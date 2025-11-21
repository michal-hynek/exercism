local Darts = {}

local function dist(x, y)
    return math.sqrt(x*x + y*y)
end

function Darts.score(x, y)
    local distance = dist(x, y)

    if distance <= 1 then
        return 10
    elseif distance <= 5 then
        return 5
    elseif distance <= 10 then
        return 1
    else
        return 0
    end
end

return Darts
