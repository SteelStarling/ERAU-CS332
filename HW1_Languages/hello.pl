use strict;
use warnings;

print("Hello Perl!\n");
while (<>) {
    print("Hello " . join("\nHello ", split(/\s+/)) . "\n");
}
