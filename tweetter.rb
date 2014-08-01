require 'twitter'
require 'serialport'
def send_tweet(txt)
client = Twitter::REST::Client.new do |config|
config.consumer_key = 'CttHz8NgS24n3ZJhuIxtOSb17'
config.consumer_secret ='zkp90JHC5qWFkawd6BbDzEghOH1IDu1KwXR4ODFSjlEbFPjmJc'
config.oauth_token = '252924295-5iykxILUtxpV1ZPQyty8LhGeoNOgfh6RWPCAz35c'
config.oauth_token_secret = 'idyBCkadfbLvx44eLOZTjVIHcGT0MzwQqiWLa381TZFY7'
end
puts "se publico"
client.update(txt)
end
anterior=0
reciente=0
port_str = "/dev/ttyACM0" #may be different for you
baud_rate = 9600
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE
sp = SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)
while true do
while (i = sp.gets) do
puts i
send_tweet("espacio disponibles"+i)
end
end
sp.close
