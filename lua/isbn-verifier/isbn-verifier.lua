local function is_digit(c)
  return c >= "0" and c <= "9"
end

return {
  valid = function(isbn)
    local sum = 0
    local isbn_len = 0
    local digit_weight = 10

    for i = 1, #isbn do
      local c = string.sub(isbn, i, i)

      if is_digit(c) then
        local digit = tonumber(c, 10)
        sum = sum + digit_weight * digit

        isbn_len = isbn_len + 1
        digit_weight = digit_weight - 1
      elseif i == #isbn and string.upper(c) == "X" then
        sum = sum + digit_weight * 10 

        isbn_len = isbn_len + 1
        digit_weight = digit_weight - 1
      elseif c ~= '-' then
        return false
      end
    end

    return isbn_len == 10 and sum % 11 == 0
  end
}
