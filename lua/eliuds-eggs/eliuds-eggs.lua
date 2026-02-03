local EliudsEggs = {}

function EliudsEggs.egg_count(number)
    local eggs = 0

    for i = 0,31 do
        if (2^i) & number ~= 0 then
            eggs = eggs + 1
        end
    end

    return eggs
end

return EliudsEggs
