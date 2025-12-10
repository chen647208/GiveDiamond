#include "Entry.h"
#include <ll/api/event/EventBus.h>
#include <ll/api/event/player/PlayerJoinEvent.h>
#include <ll/api/mod/RegisterHelper.h>
#include <mc/safety/RedactableString.h>
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
            auto item = ItemStack(VanillaItemNames::Diamond());

            auto name = Bedrock::Safety::RedactableString();
            name.set("新手礼包");
            item.setCustomName(name);

            event.self().addAndRefresh(item);
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