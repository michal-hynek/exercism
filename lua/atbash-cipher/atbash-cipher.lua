local char_mappings = {
  a = 'z',
  b = 'y',
  c = 'x',
  d = 'w',
  e = 'v',
  f = 'u',
  g = 't',
  h = 's',
  i = 'r',
  j = 'q',
  k = 'p',
  l = 'o',
  m = 'n',
  n = 'm',
  o = 'l',
  p = 'k',
  q = 'j',
  r = 'i',
  s = 'h',
  t = 'g',
  u = 'f',
  v = 'e',
  w = 'd',
  x = 'c',
  y = 'b',
  z = 'a',
}

local function is_char(c)
  return c >= 'a' and c <= 'z' or c >= 'A' and c <= 'Z'
end

local function is_digit(c)
  return c >= '0' and c <= '9'
end

return {
  encode = function(plaintext)
    local encoded = ""
    local j = 0

    for i = 1, #plaintext do
      local c = string.sub(plaintext, i, i)

      if (is_char(c) or is_digit(c)) and j > 0 and j % 5 == 0 then
        encoded = encoded .. " "
      end      

      if is_char(c) then
        encoded = encoded .. char_mappings[string.lower(c)]
        j = j + 1
      elseif is_digit(c) then
        encoded = encoded .. c
        j = j + 1
      end
    end

    return encoded
  end
}
