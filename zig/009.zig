const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn solve(n: u64) u64 {
    var sol: u64 = 0;
    for (1..n) |a| {
        for (1..n) |b| {
            for (1..n) |c| {
                if (a + b + c == n and a * a + b * b == c * c) {
                    sol = a * b * c;
                    break;
                }
            }
        }
    }

    return sol;
}

pub fn main() !void {
    try stdout.print("{}\n", .{solve(1000)});
}
