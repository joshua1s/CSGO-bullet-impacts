#include "game events.hpp"
#include "interfaces.hpp"

void gameEvents::onBulletImpact(GameEvent* event)
{
	if (interfaces.entitylist->getEntity(interfaces.engine->getPlayerForUserID(event->getInt("userid")))->index()
		!= interfaces.engine->getLocalPlayer()) return;

	Vector hitpos{ event->getFloat("x"), event->getFloat("y"), event->getFloat("z") };

	interfaces.debugOverlay->addBoxOverlay(hitpos, Vector{ 2.f, 2.f, 2.f }, Vector{ -2.f, -2.f, -2.f }, QAngle{}, 255, 0, 0, 200, 5.f);
}
