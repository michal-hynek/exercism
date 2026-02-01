local gigasecond = {}

function gigasecond.anniversary(any_date)
    local result = any_date + 1000000000

    return os.date('%x', result)
end

return gigasecond
