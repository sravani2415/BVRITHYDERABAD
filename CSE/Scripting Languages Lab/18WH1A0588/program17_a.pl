#!/usr/bin/perl
print "enter a value";
$a = <stdin>;
print "enter b value";
$b = <stdin>;
print "enter c value";
$c = <stdin>;
if($a > $b){
if($a > $c){
print "$a is largest number\n";
}
else{
print "$c is largest number\n";
}
}
elsif($b > $c){
print "$b is largest number";
}
else{
print "$c is largest number";
}
