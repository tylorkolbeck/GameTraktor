#include "gtpch.h"
#include "Layer.h"

namespace GameTraktor {
	Layer::Layer(const std::string& debugName) 
		: m_DebugName(debugName)
	{}

	Layer::~Layer() {}
}