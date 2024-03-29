add_rules("mode.debug", "mode.release") 
target("Photon") 
    set_kind("static")
    set_pcxxheader("pch.h")
    set_languages("c99","c++20")
    add_files("core/*.cpp")
target("Photon_demo")
    set_kind("binary")
    add_deps("Photon")
    add_files("demo/*.cpp")
