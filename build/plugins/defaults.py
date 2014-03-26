from simulator import *

class Sword(BaseWeapon):
    default_attributes = {}
    def __init__(self):
        BaseWeapon.__init__(self, Sword.__name__)
        additional_attributes = {}
        self.attributes = dict(Sword.default_attributes.items() +
                               additional_attributes.items())

        self.requiredItems = []
        self.damageModifiers = {
            damage_type.piercing : 2,
            damage_type.slashing : 2,
            damage_type.blunt    : 0.5
        }

class Baker(BaseProfession):
    related_items = [Sword]
    def __init__(self):
        BaseProfession.__init__(self, Baker.__name__)
        self.skillMap = {}

class Dagger(BaseWeapon):
    default_attributes = {}
    def __init__(self):
        BaseWeapon.__init__(self, Dagger.__name__)
        additional_attributes = {}
        self.attributes = dict(Dagger.default_attributes.items() +
                               additional_attributes.items())

        self.requiredItems = []
        self.damageModifiers = {
            damage_type.piercing : 2,
            damage_type.slashing : 2,
            damage_type.blunt    : 0.5
        }

class House(BaseContainer):
    default_attributes = {"habitable" : True}
    def __init__(self):
        BaseContainer.__init__(self, House.__name__)
        additional_attributes = {}
        self.requiredItems = []
        self.attributes = dict(House.default_attributes.items() +
                               additional_attributes.items())
