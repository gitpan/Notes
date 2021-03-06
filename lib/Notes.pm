package Notes;

use strict;
use warnings;
use Const::Fast;

=pod

=head1 DESCRIPTION

This script can have 1 parameter. The keynote that you need know the 8 notes.

=cut

const our %NOTES => (	           
		'A' => { 
					1   => 'A', 
					2   => 'B', 
					3   => 'C#', 
					4   => 'D', 
					5   => 'E', 
					6   => 'F#', 
					7   => 'G#', 
					8   => 'A', 
         },
  		'B' => { 
					1   => 'B', 
					2   => 'C#', 
					3   => 'D#', 
					4   => 'E', 
					5   => 'F#', 
					6   => 'G#', 
					7   => 'A#', 
					8   => 'B', 
		},			
  		'F#m' => { 
					1   => 'F#', 
					2   => 'G#', 
					3   => 'A', 
					4   => 'B', 
					5   => 'C#', 
					6   => 'D', 
					7   => 'E', 
					8   => 'F#', 
 	    }, 
  		'G#m' => { 
					1   => 'G#', 
					2   => 'A#', 
					3   => 'B', 
					4   => 'C#', 
					5   => 'D#', 
					6   => 'E', 
					7   => 'F#', 
					8   => 'G#', 
    	 },    		   
  		'C' => { 
					1   => 'C', 
					2   => 'D', 
					3   => 'E', 
					4   => 'F', 
					5   => 'G', 
					6   => 'A', 
					7   => 'B', 
					8   => 'C', 
    	 },    		   
  		'Am' => { 
					1   => 'A', 
					2   => 'B', 
					3   => 'C', 
					4   => 'D', 
					5   => 'E', 
					6   => 'F', 
					7   => 'G', 
					8   => 'C', 
    	 },    		   
  		'D' => { 
					1   => 'D', 
					2   => 'E', 
					3   => 'F#', 
					4   => 'G', 
					5   => 'A', 
					6   => 'B', 
					7   => 'C#', 
					8   => 'D', 
    	 },    		   
  		'Bm' => { 
					1   => 'B', 
					2   => 'C#', 
					3   => 'D', 
					4   => 'E', 
					5   => 'F#', 
					6   => 'G', 
					7   => 'A', 
					8   => 'B', 
    	 },    		   
  		'E' => { 
					1   => 'E', 
					2   => 'F#', 
					3   => 'G#', 
					4   => 'A', 
					5   => 'B', 
					6   => 'C#', 
					7   => 'D#', 
					8   => 'E', 
    	 },    		   
  		'C#m' => { 
					1   => 'C#', 
					2   => 'D#', 
					3   => 'E', 
					4   => 'F#', 
					5   => 'G#', 
					6   => 'A', 
					7   => 'B', 
					8   => 'C#m', 
    	 },
  		'F' => { 
					1   => 'F', 
					2   => 'G', 
					3   => 'A', 
					4   => 'Bb', 
					5   => 'C', 
					6   => 'D', 
					7   => 'E', 
					8   => 'F', 
    	 },
  		'Dm' => { 
					1   => 'D', 
					2   => 'E', 
					3   => 'F', 
					4   => 'G', 
					5   => 'A', 
					6   => 'Bb', 
					7   => 'C', 
					8   => 'D', 
    	 },
  		'G' => { 
					1   => 'G', 
					2   => 'A', 
					3   => 'B', 
					4   => 'C', 
					5   => 'D', 
					6   => 'E', 
					7   => 'F#', 
					8   => 'G', 
    	 },
  		'Em' => { 
					1   => 'E', 
					2   => 'F#', 
					3   => 'G', 
					4   => 'A', 
					5   => 'B', 
					6   => 'C', 
					7   => 'D', 
					8   => 'E', 
    	 },
  		'A#' => { 
					1   => 'A#', 
					2   => 'C', 
					3   => 'D', 
					4   => 'D#', 
					5   => 'F', 
					6   => 'G', 
					7   => 'A', 
					8   => 'A#', 
    	 },
  		'Gm' => { 
					1   => 'G', 
					2   => 'A', 
					3   => 'A#', 
					4   => 'C', 
					5   => 'D', 
					6   => 'D#', 
					7   => 'F', 
					8   => 'G#', 
    	 },
  		'C#' => { 
					1   => 'C#', 
					2   => 'D#', 
					3   => 'F', 
					4   => 'F#', 
					5   => 'G#', 
					6   => 'A#', 
					7   => 'C', 
					8   => 'C#', 
    	 },
  		'A#m' => { 
					1   => 'A#', 
					2   => 'C', 
					3   => 'C#', 
					4   => 'D#', 
					5   => 'F', 
					6   => 'F#', 
					7   => 'G#', 
					8   => 'A', 
    	 },
  		'D#' => { 
					1   => 'D#', 
					2   => 'F', 
					3   => 'G', 
					4   => 'G#', 
					5   => 'A#', 
					6   => 'C', 
					7   => 'D', 
					8   => 'D#', 
    	 },
  		'Cm' => { 
					1   => 'C', 
					2   => 'D', 
					3   => 'D#', 
					4   => 'F', 
					5   => 'G', 
					6   => 'G#', 
					7   => 'A#', 
					8   => 'C', 
    	 },
  		'F#' => { 
					1   => 'F#', 
					2   => 'G#', 
					3   => 'A#', 
					4   => 'B', 
					5   => 'C#', 
					6   => 'D#', 
					7   => 'F', 
					8   => 'F#', 
    	 },
  		'D#m' => { 
					1   => 'D#', 
					2   => 'F', 
					3   => 'F#', 
					4   => 'G#', 
					5   => 'A#', 
					6   => 'B', 
					7   => 'C#', 
					8   => 'D#', 
    	 },
  		'G#' => { 
					1   => 'G#', 
					2   => 'A#', 
					3   => 'C', 
					4   => 'C#', 
					5   => 'D#', 
					6   => 'F', 
					7   => 'G', 
					8   => 'G#', 
    	 },
  		'Fm' => { 
					1   => 'F', 
					2   => 'G', 
					3   => 'G#', 
					4   => 'A#', 
					5   => 'C', 
					6   => 'C#', 
					7   => 'D#', 
					8   => 'F', 
    	 },		 
	); 

sub match{
	my ( $self, $note ) = @_;
    
    die "please set parameter note" unless $note;

	die "parameter not is valid" unless $note =~ /[A-Z]|[A-Z][#bm]|[A-Z][#b]m/;

	die "tone not is valid" unless exists $NOTES{$note}; 

    return %{$NOTES{$note}};

};



1;

# ABSTRACT: return the 8 notes of your keynote.
