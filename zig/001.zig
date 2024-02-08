const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn solve(limit: usize) usize {
    var total: usize = 0;
    for (1..limit) |i| {
        if (@mod(i, 3) == 0 or @mod(i, 5) == 0) {
            total += i;
        }
    }

    return total;
}

pub fn main() !void {
    var sum: usize = solve(1000);
    try stdout.print("{}\n", .{sum});
}
