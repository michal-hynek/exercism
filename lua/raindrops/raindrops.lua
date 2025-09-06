return function(n)
    local result = ""
    local is_divisible = false

    if n % 3 == 0 then
        result = "Pling"
        is_divisible = true
    end

    if n % 5 == 0 then
        result = result .. "Plang"
        is_divisible = true
    end

    if n % 7 == 0 then
        result = result .. "Plong"
        is_divisible = true
    end

    if is_divisible == false then 
        return tostring(n)
    end

    return result
end
