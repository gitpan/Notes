#/usr/bin/perl

use strict;
use warnings;

use Test::Most;
use Test::Exception;

use Notes;

{
	my %notes = Notes->match('B');

	my $quantity = scalar(keys %notes);

	is($quantity, 8, 'quantidade correta de notas');

}

{

	throws_ok { Notes->match('1') } qr/parameter not is valid/, 'send value wrong';

}
done_testing;


