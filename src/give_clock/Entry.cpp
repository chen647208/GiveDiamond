#include "Entry.h"
#include <ll/api/event/EventBus.h>
#include <ll/api/event/player/PlayerJoinEvent.h>
#include <ll/api/mod/RegisterHelper.h>
#include <mc/nbt/CompoundTagVariant.h>
#include <mc/safety/RedactableString.h>
#include <mc/world/actor/player/Inventory.h>
#include <mc/world/actor/player/PlayerInventory.h>
#include <mc/world/item/ItemLockHelper.h>
#include <mc/world/item/ItemLockMode.h>
#include <mc/world/item/ItemStack.h>
#include <mc/world/item/VanillaItemNames.h>

namespace give_diamond {

Entry& Entry::getInstance() {
    static Entry instance;
    return instance;
}

bool Entry::load() { return true; }

bool Entry::enable() {
    mListener = ll::event::EventBus::getInstance().emplaceListener<ll::event::PlayerJoinEvent>(
        [](ll::event::PlayerJoinEvent& event) {
            auto& inventory = event.self().mInventory->mInventory;

            auto has_diamond = std::find_if(
                inventory->mItems->begin(),
                inventory->mItems->end(),
                [](ItemStack& item) {
                    return item.getTypeName() == VanillaItemNames::Diamond().getString();
                }
            ) != inventory->mItems->end();

            if (!has_diamond) {
                auto item = ItemStack(VanillaItemNames::Diamond());

                item.mUserData = std::make_unique<CompoundTag>(CompoundTag{
                    {"ench",                    ListTag{}                                        },
                    {"minecraft:keep_on_death", true                                             },
                    {"minecraft:item_lock",     static_cast<uchar>(ItemLockMode::LockInInventory)}
                });

                item.setCustomLore({
                    "§r§6The diamond given by the system | 由系统给予的钻石§r"
                });

                auto name = Bedrock::Safety::RedactableString();
                name.set("§r§b新手礼包§r");
                item.setCustomName(name);

                event.self().addAndRefresh(item);
            }
        }
    );
    return true;
}

bool Entry::disable() {
    ll::event::EventBus::getInstance().removeListener(mListener);
    return true;
}

bool Entry::unload() { return true; }

}

LL_REGISTER_MOD(give_diamond::Entry, give_diamond::Entry::getInstance());