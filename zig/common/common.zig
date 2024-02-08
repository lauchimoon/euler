const std = @import("std");

pub fn load_triangle(allocator: *std.mem.Allocator, data: []const u8) ![][]u16 {
    var lines = std.mem.split(u8, data, "\n");
    var line_count: usize = 0;
    while (lines.next()) |_| {
        line_count += 1;
    }

    line_count -= 1;
    var triangle = (alloc2d(u16, line_count, line_count, allocator) catch null).?;
    lines.reset();

    var y: u16 = 0;
    while (lines.next()) |line| {
        var num = std.mem.split(u8, line, " ");
        var n = num.first();
        while (n.len > 0) {
            for (0..line_count) |x| {
                var n_triangle: u16 = 0;
                if (x <= y) {
                    n_triangle = std.fmt.parseInt(u16, n, 10) catch 0;
                    n = num.next() orelse "";
                } else {
                    n_triangle = 0;
                }

                triangle[y][x] = n_triangle;
            }
        }

        y += 1;
    }

    return triangle;
}

pub fn unload_triangle(triangle: [][]u16, allocator: *std.mem.Allocator) void {
    free2d(u16, triangle, allocator);
}

fn alloc2d(comptime T: type, width: usize, height: usize, allocator: *std.mem.Allocator) ![][]T {
    var array = try allocator.alloc([]T, height);
    for (array, 0..) |_, i| {
        array[i] = try allocator.alloc(T, width);
    }

    return array;
}

fn free2d(comptime T: type, array: [][]T, allocator: *std.mem.Allocator) void {
    for (array, 0..) |_, i| {
        allocator.free(array[i]);
    }
    allocator.free(array);
}
