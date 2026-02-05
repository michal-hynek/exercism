local function is_char(c)
    return c >= 'a' and c <= 'z' or c >= 'A' and c <= 'Z'
end

return function(s)
    local chars = {}
    local s = string.lower(s)

    for i = 1, #s do
        local c = string.sub(s, i, i)

        if is_char(c) and chars[c] ~= nil then
            return false
        end

        chars[c] = true
    end

    return true
end
