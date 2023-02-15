#ifndef MORPHY_TESTS_TEST_SCENE_TREE_HPP
#define MORPHY_TESTS_TEST_SCENE_TREE_HPP

#include <godot_cpp/classes/scene_tree.hpp>

namespace morphy {

class TestSceneTree : public godot::SceneTree {
	GDCLASS(TestSceneTree, godot::SceneTree);

public:
	TestSceneTree();

	virtual void _initialize() override;

protected:
	static void _bind_methods();
};

} // namespace morphy

#endif // MORPHY_TESTS_TEST_SCENE_TREE_HPP
