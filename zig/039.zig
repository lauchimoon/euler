const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn triangleSolutions(perimeter: u64) u64 {
    var count: u64 = 0;

    for (1..perimeter/2) |a| {
        for (a..perimeter + 1) |b| {
            const c = @abs(perimeter) - @abs(a) - @abs(b);
            if (a + b + c == perimeter and a*a + b*b == c*c) {
                count += 1;
            }
        }
    }

    return count;
}

pub fn main() !void {
    std.debug.print("{}\n", .{triangleSolutions(120)});
}
