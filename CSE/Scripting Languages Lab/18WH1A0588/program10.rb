student_marks = Hash.new()
student_marks['Literature'] = gets.to_i
student_marks['Science'] = gets.to_i
student_marks['Math'] = gets.to_i
total_marks = 0
student_marks.each{|key,value|
total_marks += value
}
puts "Total Marks: "+total_marks.to_s
