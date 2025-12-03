{
    files = {
        [[build\.objs\GiveDiamond\windows\x64\release\src\give_clock\Entry.cpp.obj]],
        [[build\.objs\GiveDiamond\windows\x64\release\src\give_clock\MemoryOperators.cpp.obj]]
    },
    values = {
        [[C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.44.35207\bin\HostX64\x64\link.exe]],
        {
            "-nologo",
            "-machine:x64",
            [[-libpath:build\.prelink\lib]],
            [[-libpath:C:\Users\wuyue\AppData\Local\.xmake\packages\l\levilamina\1.7.6\2e479c2cecf544579113c7550ca8dd6d\lib]],
            [[-libpath:C:\Users\wuyue\AppData\Local\.xmake\packages\f\fmt\11.2.0\ee1902dd7cff4195a287949f80dbce70\lib]],
            [[-libpath:C:\Users\wuyue\AppData\Local\.xmake\packages\l\leveldb\1.23\2532d000dc9d47cbb618c80ba0e6d806\lib]],
            [[-libpath:C:\Users\wuyue\AppData\Local\.xmake\packages\s\snappy\1.2.2\b3244272357b4994abb43dc0aa939d28\lib]],
            [[-libpath:C:\Users\wuyue\AppData\Local\.xmake\packages\s\symbolprovider\v1.2.0\716edebcb0f14dbbbc97a0d6aa352593\lib]],
            "/opt:ref",
            "/opt:icf",
            "-debug",
            [[-pdb:build\windows\x64\release\GiveDiamond.pdb]],
            "bedrock_runtime_api.lib",
            "LeviLamina.lib",
            "fmt.lib",
            "leveldb.lib",
            "snappy.lib",
            "SymbolProvider.lib",
            "/DELAYLOAD:bedrock_runtime.dll"
        }
    }
}