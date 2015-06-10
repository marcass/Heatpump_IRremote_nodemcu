--mqtt.lua  
 
DeviceID="panasonic"  
RoomID="hall"  
Broker="enter pi ip here"  
PINON 	= "1"
PINOFF	= "2"
-- Setup hardware
	-- set pins to output
		-- set gpio "PINON" as output 
    		gpio.mode(PINON, gpio.OUTPUT)
		-- set gpio "PINOFF" as output 
    		gpio.mode(PINOFF, gpio.OUTPUT)

 m = mqtt.Client("ESP8266".. DeviceID, 180, "user", "password")  
 m:lwt("/lwt", "ESP8266", 0, 0)  
 m:on("offline", function(con)   
    print ("Mqtt Reconnecting...")   
    tmr.alarm(1, 10000, 0, function()  
      m:connect(Broker, 1883, 0, function(conn)   
        print("Mqtt Connected to:" .. Broker)  
        mqtt_sub() --run the subscription function  
      end)  
    end)  
 end)  

 -- on publish message receive event  
 m:on("message", function(conn, topic, data)   
    print("Recieved:" .. topic .. ":" .. data)   
      if (data=="ON") then  
      print("Turning on")   
      gpio.write(PINON,gpio.HIGH)  gpio.write(PINOFF,gpio.LOW)
      m:publish("/home/".. RoomID .."/" .. DeviceID .. "/p1/state","ON",0,0)  
    elseif (data=="OFF") then  
      print("Turning off")   
      gpio.write(PINOFF,gpio.HIGH) gpio.write(PINON,gpio.LOW) 
      m:publish("/home/".. RoomID .."/" .. DeviceID .. "/p1/state","OFF",0,0)  
    else  
      print("Invalid - Ignoring") gpio.write(PINOFF,gpio.LOW) gpio.write(PINON,gpio.LOW)
    end   
 end)  
 function mqtt_sub()  
    m:subscribe("/home/".. RoomID .."/" .. DeviceID .. "/p1/com",0, function(conn)   
      print("Mqtt Subscribed to OpenHAB feed for device " .. DeviceID)  
    end)  
 end  
 tmr.alarm(0, 1000, 1, function()  
  if wifi.sta.status() == 5 and wifi.sta.getip() ~= nil then  
    tmr.stop(0)  
    m:connect(Broker, 1883, 0, function(conn)   
      print("Mqtt Connected to:" .. Broker)  
      mqtt_sub() --run the subscription function  
    end)  
  end  
 end)