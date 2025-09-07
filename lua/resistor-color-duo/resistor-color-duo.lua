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

return {
  value = function(colors)
    if #colors == 0 then
      return 0
    elseif #colors == 1 then
      return color_values[colors[1]]
    else
      return color_values[colors[1]]*10 + color_values[colors[2]]
    end
  end
}
