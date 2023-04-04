# this is the contents of hello.awk

function greet(n) {
    # print outputs a sequence of fields separated by the OFS delimiter
    print "Hello", n
}

BEGIN {
    print "Hello Awk!"
}

{
    # process each input field on the current line, one at a time
    for(i = 1; i <= NF; ++i)
        greet($i)
}

END {
    print "bye"
}
