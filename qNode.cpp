#include "qNode.h"

qNode::qNode() {}
qNode::qNode(btNode* d) :data(d), next(nullptr) {}