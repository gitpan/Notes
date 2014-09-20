requires "Const::Fast" => "0";
requires "strict" => "0";
requires "warnings" => "0";

on 'configure' => sub {
  requires "ExtUtils::MakeMaker" => "0";
};
