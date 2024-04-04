const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn collatzAtt(n: u64) u64 {
    var term: u64 = n;
    var attempts: u64 = 0;

    while (term != 1) {
        if (@mod(term, 2) == 0) {
            term /= 2;
        } else {
            term = 3*term + 1;
        }

        attempts += 1;
    }

    return attempts;
}

fn solve(limit: u64) u64 {
    var max: u64 = 0;
    var answer: u64 = 0;

    for (5..limit) |i| {
        const attempts: u64 = collatzAtt(i);
        if (attempts > max) {
            max = attempts;
            answer = i;
        }
    }

    return answer;
}

pub fn main() !void {
    try stdout.print("{}\n", .{solve(1000000)});
}
