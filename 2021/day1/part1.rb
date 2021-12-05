file = "input.txt"

prev_val = -1
cnt = 0
File.open(file).each do |line|
  val = line.to_i
  print val
  if prev_val == -1 then
    prev_val = val
  else
    if val > prev_val then 
      puts "inc"
      cnt += 1 
    else
      puts "non"
    end
    prev_val = val
  end
end

puts cnt
