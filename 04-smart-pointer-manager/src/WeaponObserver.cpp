#include "WeaponObserver.hpp"

void WeaponObserver::watch(const std::shared_ptr<Weapon>& p_weapon) { m_weapon = p_weapon; }
void WeaponObserver::display_weapon_status() const { m_weapon.lock()->display_status(); }
bool WeaponObserver::is_available() const { return m_weapon.expired(); }