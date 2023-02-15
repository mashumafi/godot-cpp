#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

env.Append(CPPPATH=["include", "include/morphy"] + ["thirdparty/Catch2/extras"])
sources = [Glob("src/morphy/*.cpp"), Glob("src/morphy/views/*.cpp"), Glob("src/morphy/tests/*.cpp"), "thirdparty/Catch2/extras/catch_amalgamated.cpp"]

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "game/bin/morphy/libgdmorphy.{}.{}.framework/libgdmorphy.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "game/bin/morphy/libgdmorphy{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
