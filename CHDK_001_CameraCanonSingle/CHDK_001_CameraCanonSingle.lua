--[[
@title Single shot
@chdk_version 1.4
--]]

while (1) do
    wait_click(1)
    if is_pressed "remote" then shoot() end
end
