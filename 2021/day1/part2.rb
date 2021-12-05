file = "input.txt"

(v1, v2, v3) = [-1, -1, -1]
cnt = 0
seen = 0

File.open(file).each do |line|
  val = line.to_i
  seen += 1

  if seen > 3 and (v1 + v2 + v3) < (v2 + v3 + val) then 
    p ([v2, v3, val].join(':') + " > " + [v1, v2, v3].join(':'))
    cnt += 1 
  end

  # mod the arr
  (v1, v2, v3) = [v2, v3, val]
end

puts cnt
