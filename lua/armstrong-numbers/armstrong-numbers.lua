local ArmstrongNumbers = {}

local function digits_len(number)
    if number == 0 then
        return 1
    end

    local digits = 0

    while number > 0 do
        digits = digits + 1
        number = math.floor(number / 10)
    end

    return digits
end

function ArmstrongNumbers.is_armstrong_number(number)
    local pow = digits_len(number)
    local sum = 0
    local x = number

    while x > 0 do
        local digit = x % 10
        sum = sum + (digit ^ pow)

        x = math.floor(x / 10)
    end

    return sum == number
end

return ArmstrongNumbers
