# Panoramix

## Context

> The year is 50 BC. Gaul is entirely occupied by the Romans. Well, not entirely... One small village of indomitable Gauls still holds out against the invaders. And life is not easy for the Roman legionaries who
garrison the fortified camps of Totorum, Aquarium, Laudanum and Compendium...

In this village the druid prepares a cooking pot of magic potions. The villagers get a serving of potion and
then procede to beat roman soldiers. When the pot is empty, the villager wakes up the druid and waits until
the druid has refilled the pot.

## Build

```
>> ./build.sh
```

> Requirements: CMake

## Usage

```
>> ./panoramix
USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
```

* `nb_villagers`: indicates the number of villagers (must be >0)
* `pot_size`: indicates the maximum number that can be contained in the cooking pot (must be > 0)
* `nb_fights`: indicates the maximum number of fights a villager will engage in (must be > 0)
* `nb_refills`: incicates the maximum number of time the druid will refill the pot (must be > 0)

---
© Corentin COUTRET ROZET