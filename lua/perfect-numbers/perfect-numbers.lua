local function aliquot_sum(n)
    local sum = 0

    for i = 1, math.floor(math.sqrt(n)) do
        if i ~= n and n % i == 0 then
            sum = sum + i

            local complement = n / i

            if complement ~= n and complement ~= i then
                sum = sum + complement
            end
        end
    end

    return sum
end

local function classify(n)
    local sum = aliquot_sum(n)

    if n < sum then
        return 'abundant'
    elseif n > sum then
        return 'deficient'
    else
        return 'perfect'
    end
end

return { aliquot_sum = aliquot_sum, classify = classify }
