local TwoFer = {}

function TwoFer.two_fer(name)
    if name == nil or #name == 0 then
        return "One for you, one for me."
    else
        return "One for " .. name .. ", one for me."
    end
end

return TwoFer
