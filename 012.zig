const std = @import("std");
const stdout = std.io.getStdOut().writer();
const common = @import("common");

fn tri(n: u64) u64 {
    return n*(n + 1)/2;
}

fn solve(n_divs: u64) !u64 {
    var i: usize = 0;
    while (true) : (i += 1) {
        const tri_i = tri(i);
        const divs = try common.nDivs(tri_i);
        if (divs > n_divs) {
            return tri_i;
        }
    }

    return -1;
}

pub fn main() !void {
    const solution = try solve(500);
    try stdout.print("{}\n", .{solution});
}
