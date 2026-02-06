local function is_upper(c)
  return c >= 'A' and c <= 'Z'
end

local function is_lower(c)
  return c >= 'a' and c <= 'z'
end

local function shift_char(c, base, shift)
  local char_val = string.byte(c, 1, 1)
  local shifted_val = base + (char_val + shift - base) % 26

  return string.char(shifted_val)
end

return {
  rotate = function(input, key)
    local rotated = ''

    for i = 1, #input do
      local c = string.sub(input, i, i)

      if is_upper(c) then
        rotated = rotated .. shift_char(c, string.byte("A", 1, 1), key)
      elseif is_lower(c) then
        rotated = rotated .. shift_char(c, string.byte("a", 1, 1), key)
      else
        rotated = rotated .. c 
      end
    end

    return rotated
  end
}
