local Hamming = {}

function Hamming.compute(a, b)
    if #a ~= #b then
        error("strands must be of equal length")
    end

    local distance = 0

    for i = 1, #a do
        local c1 = string.sub(a, i, i)
        local c2 = string.sub(b, i, i)

        if c1 ~= c2 then
            distance = distance + 1
        end
    end

    return distance
end

return Hamming
