--[[
@title Multi Trigger
@chdk_version 1.4
--]]
function triggerA()
	print("20 ms pulse")
	set_zoom(0)
	shoot()
end

function triggerB()
	print("50 ms pulse")
	set_zoom(20)
	shoot()
end

function triggerC()
	print("80 ms pulse")
	set_zoom(40)
	shoot()
end

function triggerD()
	print("110 ms pulse")
	set_zoom(60)
	shoot()
end

function triggerE()
	print("140 ms pulse")
	set_zoom(80)
	shoot()
end

function triggerF()
	print("170 ms pulse")
	set_zoom(100)
	shoot()
end


print "Start Multi trigger levels by Arduino"
while (1) do
	repeat
       a = get_usb_power(0)
    until a>0
    if (a >= 1 and  a <= 3) then triggerA() end 
    if (a >= 4 and  a <= 6) then triggerB() end
    if (a >= 7 and  a <= 9) then triggerC() end
    if (a >= 10 and a <= 12) then triggerD() end
    if (a >= 13 and a <= 15) then triggerE() end
    if (a >= 16 and a <= 18) then triggerF() end
    if (a > 19) then print "error" end
end

