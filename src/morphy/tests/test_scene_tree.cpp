#include <tests/test_scene_tree.hpp>

#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include <catch_amalgamated.hpp>

#include <string>
#include <vector>

namespace morphy {

TestSceneTree::TestSceneTree() {
}

void TestSceneTree::_bind_methods() {
}

void TestSceneTree::_initialize() {
	SceneTree::_initialize();

	bool run_tests = false;

	std::vector<std::string> args;
	std::vector<char *> raw_args;
	godot::PackedStringArray os_args = godot::OS::get_singleton()->get_cmdline_args();
	godot::UtilityFunctions::prints("There are ", os_args.size(), "args");

	args.push_back(godot::OS::get_singleton()->get_executable_path().ascii().get_data());
	raw_args.push_back(args.back().data());

	for (int i = 0; i < os_args.size(); ++i) {
		godot::UtilityFunctions::prints("Arg", i, os_args[i]);
		if (os_args[i] == "--morphy-test") {
			run_tests = true;
			continue;
		}

		args.push_back(os_args[i].ascii().get_data());
		raw_args.push_back(args[i].data());
	}

	if (!run_tests) {
		godot::UtilityFunctions::print("Skipping tests");
		return;
	}

	int result = Catch::Session().run(raw_args.size(), raw_args.data());
}

} //namespace morphy
