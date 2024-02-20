// NOTE: there's probably another way
// rather than comptime exploiting. :P
const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn unit(comptime n: u64) []const u8 {
    switch (n) {
        0 => return "zero",
        1 => return "one",
        2 => return "two",
        3 => return "three",
        4 => return "four",
        5 => return "five",
        6 => return "six",
        7 => return "seven",
        8 => return "eight",
        9 => return "nine",
        else => return "unknown",
    }
}

fn uniqueTwoDigit(comptime n: u64) []const u8 {
    switch (n) {
        10 => return "ten",
        11 => return "eleven",
        12 => return "twelve",
        13 => return "thirteen",
        14 => return "fourteen",
        15 => return "fifteen",
        16 => return "sixteen",
        17 => return "seventeen",
        18 => return "eighteen",
        19 => return "nineteen",
        else => return "unknown",
    }
}

fn twoDigit(comptime n: u64) []const u8 {
    const prefixes = comptime [8][]const u8{
        "twenty","thirty", "forty",
        "fifty", "sixty", "seventy",
        "eighty", "ninety",
    };

    const first = comptime n/10;
    const second = comptime n%10;

    if (first == 0) {
        return unit(second);
    } else if (first == 1 and (second >= 0 and second <= 9)) {
        return uniqueTwoDigit(n);
    } else if (second == 0) {
        return prefixes[first - 2];
    } else {
        const single = comptime unit(second);
        return prefixes[first - 2] ++ single;
    }
}

fn threeDigit(comptime n: u64) []const u8 {
    const first = comptime n/100;
    const last_two = comptime n%100;

    comptime var num = unit(first) ++ "hundred";
    if (last_two == 0) {
        return num;
    } else {
        return num ++ "and" ++ comptime twoDigit(last_two);
    }
}

fn nToWord(comptime n: u64) []const u8 {
    switch (n) {
        0...9 => return unit(n),
        10...19 => return uniqueTwoDigit(n),
        20...99 => return twoDigit(n),
        100...999 => return threeDigit(n),
        1000 => return "onethousand",
        else => return "unknown",
    }
}

fn solve(comptime n: u64) u64 {
    comptime var i: u64 = 1;
    var total: u64 = 0;
    inline while (i <= n) : (i += 1) { // For some reason you cannot exceed 1000 loops. Lol!
        total += nToWord(i).len;
    }

    return total;
}

pub fn main() !void {
    try stdout.print("{}\n", .{solve(1000)});
}
