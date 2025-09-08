local color_values = {
  black = 0,
  brown = 1,
  red = 2,
  orange = 3,
  yellow = 4,
  green = 5,
  blue = 6,
  violet = 7,
  grey = 8,
  white = 9,
}

local units = {
  ohms = 1,
  kiloohms = 1000,
  megaohms = 1000000,
  gigaohms = 1000000000,
  teraohms = 1000000000000,
}

local get_unit = function(value)
  if value < units.kiloohms then
    return "ohms", units.ohms
  elseif value < units.megaohms then
    return "kiloohms", units.kiloohms
  elseif value < units.gigaohms then
    return "megaohms", units.megaohms
  elseif value < units.teraohms then
    return "gigaohms", units.gigaohms
  else
    return "teraohms", units.teraohms
  end
end

local get_value = function(c1, c2, c3)
  local base = color_values[c1]*10 + color_values[c2]
  local exp = color_values[c3]

  return base * (10^exp)
end


return {
  decode = function(c1, c2, c3)
    local value = get_value(c1, c2, c3)
    local unit_name, unit_weight = get_unit(value)

    return value / (unit_weight), unit_name
  end
}
