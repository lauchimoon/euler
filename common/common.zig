const std = @import("std");
const pow = std.math.pow;

pub fn loadTriangle(allocator: *std.mem.Allocator, data: []const u8) ![][]u16 {
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

pub fn unloadTriangle(triangle: [][]u16, allocator: *std.mem.Allocator) void {
    free2d(u16, triangle, allocator);
}

pub fn minDiv(n: u64) u64 {
    var min: u64 = 2;
    while (true) : (min += 1) {
        if (@mod(n, min) == 0) {
            return min;
        }
    }
}

pub fn sumDiv(n: u64) !u64 {
    const allocator = std.heap.page_allocator;
    var coeffs = std.ArrayList(u64).init(allocator);
    var powers = std.AutoHashMap(u64, u64).init(allocator);
    defer coeffs.deinit();
    defer powers.deinit();

    var sd: u64 = 1;
    var n0: u64 = n;

    while (n0 > 1) {
        var m = minDiv(n0);
        n0 /= m;
        try coeffs.append(m);
    }

    for (coeffs.items) |coeff| {
        if (powers.get(coeff)) |p| {
            try powers.put(coeff, p + 1);
        } else {
            try powers.put(coeff, 1);
        }
    }

    var it = powers.iterator();
    while (it.next()) |item| {
        const coeff = item.key_ptr.*;
        const power = item.value_ptr.*;
        sd *= (pow(u64, coeff, power + 1) - 1)/(coeff - 1);
    }

    return sd - n;
}

pub fn maxList(comptime T: type, list: std.ArrayList(T)) T {
    var m: T = 0;
    for (list.items) |item| {
        m = @max(m, item);
    }

    return m;
}

pub fn nDivs(n: u64) !u64 {
    const allocator = std.heap.page_allocator;
    var coeffs = std.ArrayList(u64).init(allocator);
    var powers = std.AutoHashMap(u64, u64).init(allocator);
    defer coeffs.deinit();
    defer powers.deinit();

    var nd: u64 = 1;
    var n0: u64 = n;

    while (n0 > 1) {
        var m = minDiv(n0);
        n0 /= m;
        try coeffs.append(m);
    }

    for (coeffs.items) |coeff| {
        if (powers.get(coeff)) |p| {
            try powers.put(coeff, p + 1);
        } else {
            try powers.put(coeff, 1);
        }
    }

    var it = powers.iterator();
    while (it.next()) |item| {
        const power = item.value_ptr.*;
        nd *= power + 1;
    }

    return nd;
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
