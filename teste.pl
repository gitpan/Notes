#!/usr/bin/perl

use strict;
use warnings;
use Data::Dumper;
use Notes;


my %values = Notes->match('B');

#print Dumper \%values;

for my $key ( sort {$a <=> $b } keys %values ){
	print $key," => ",$values{$key},"\n";
}

