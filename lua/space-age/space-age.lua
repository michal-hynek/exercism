local seconds_in_earth_year = 31557600.0

local planet_orbits = {
    mercury = 0.2408467,
    venus = 0.61519726,
    earth = 1.0,
    mars = 1.8808158,
    jupiter = 11.862615,
    saturn = 29.447498,
    uranus = 84.016846,
    neptune = 164.79132,
}

local round = function(val)
    return math.floor(val * 100 + 0.5) / 100
end

local SpaceAge = {
    new = function(self, seconds)
        return {
            seconds = seconds,

            on_earth = function()
                return round(seconds / seconds_in_earth_year / planet_orbits.earth)
            end,

            on_mercury = function()
                return round(seconds / seconds_in_earth_year / planet_orbits.mercury)
            end,

            on_venus = function()
                return round(seconds / seconds_in_earth_year / planet_orbits.venus)
            end,

            on_mars = function()
                return round(seconds / seconds_in_earth_year / planet_orbits.mars)
            end,

            on_jupiter = function()
                return round(seconds / seconds_in_earth_year / planet_orbits.jupiter)
            end,

            on_saturn = function()
                return round(seconds / seconds_in_earth_year / planet_orbits.saturn)
            end,

            on_uranus = function()
                return round(seconds / seconds_in_earth_year / planet_orbits.uranus)
            end,

            on_neptune = function()
                return round(seconds / seconds_in_earth_year / planet_orbits.neptune)
            end,
        }
    end
}

return SpaceAge
