const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn solve(limit: usize) usize {
    var a: usize = 1;
    var b: usize = 2;
    var next: usize = a + b;
    var total: usize = b;

    while (next < limit) {
        a = b;
        b = next;
        next = a + b;

        if (@mod(next, 2) == 0) {
            total += next;
        }
    }

    return total;
}

pub fn main() !void {
    var sum: usize = solve(4000000);
    try stdout.print("{}\n", .{sum});
}
