#include "Normal.h"
#include "constants.h"

ppd Normal(ppd VertexPos1, ppd VertexPos2) {
	// VertexPos1 is the older Vertex(Pos 2 is A & Pos 1 is B)
	ppd V21 = vec2d::Sub(VertexPos1, VertexPos2);
	ppd V2o = vec2d::CalculateMagnitude(-VertexPos2.first.first, -VertexPos2.first.second, 0);
	return vec2d::CalculateMagnitude(abs(V2o.second.first) * sin(V21.second.second - V2o.second.second), V21.second.second - PI / 2, 1);
}
ppd ClosesToOrigin(ppd VertexPos1, ppd VertexPos2) {
	ppd V2o = vec2d::CalculateMagnitude(-VertexPos2.first.first, -VertexPos2.first.second, 0);
	ppd N = Normal(VertexPos1, VertexPos2);
	if (vec2d::Dot(N, V2o) < 0) return N;
	return vec2d::CalculateMagnitude(-N.first.first, -N.first.second, 0);
}
ppd NormalToOrigin(ppd VertexPos1, ppd VertexPos2) {
	ppd V2o = vec2d::CalculateMagnitude(-VertexPos2.first.first, -VertexPos2.first.second, 0);
	ppd N = Normal(VertexPos1, VertexPos2);
	if (vec2d::Dot(N, V2o) > 0) return N;
	return vec2d::CalculateMagnitude(-N.first.first, -N.first.second, 0);
}
