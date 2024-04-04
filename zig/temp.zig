const stdout = @import("std").io.getStdOut().writer();
const common = @import("common");

pub fn main() !void {
    try stdout.print("{any}\n", .{common.sumDiv(24)});
}
