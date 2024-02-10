const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn solve(divs: u64) u64 {
    var sum: u64 = 0;
    var cnt: u64 = 1;

    while (true) {
        sum += cnt;
        cnt += 1;

        var ndivs: i32 = 0;
        var i: u64 = 1;
        while (i*i <= sum) {
            if (@mod(sum, i) == 0) {
                ndivs += 2;
            }
            i += 1;
        }

        if (ndivs >= divs) {
            return sum;
        }
    }

    return -1;
}

pub fn main() !void {
    try stdout.print("{}\n", .{solve(500)});
}
