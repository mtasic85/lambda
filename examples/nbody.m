import sys

PI = 3.141592653589793
SOLAR_MASS = 4.0 * PI * PI
DAYS_PER_YEAR = 365.24


class Body
    def __new__(self, x, y, z, vx, vy, vz, mass)
        self.x = x
        self.y = y
        self.z = z
        self.vx = vx
        self.vy = vy
        self.vz = vz
        self.mass = mass
        return self


    def offsetMomentum(self, px, py, pz)
        self.vx = -px / SOLAR_MASS
        self.vy = -py / SOLAR_MASS
        self.vz = -pz / SOLAR_MASS
        return self


class Jupiter(Body)
    def __new__(self)
        return Body.__new__(
            self,
            4.84143144246472090e+00,
            -1.16032004402742839e+00,
            -1.03622044471123109e-01,
            1.66007664274403694e-03 * DAYS_PER_YEAR,
            7.69901118419740425e-03 * DAYS_PER_YEAR,
            -6.90460016972063023e-05 * DAYS_PER_YEAR,
            9.54791938424326609e-04 * SOLAR_MASS,
        )


class Saturn(Body)
   def __new__(self)
        return Body.__new__(
            self,
            8.34336671824457987e+00,
            4.12479856412430479e+00,
            -4.03523417114321381e-01,
            -2.76742510726862411e-03 * DAYS_PER_YEAR,
            4.99852801234917238e-03 * DAYS_PER_YEAR,
            2.30417297573763929e-05 * DAYS_PER_YEAR,
            2.85885980666130812e-04 * SOLAR_MASS,
        )


class Uranus(Body)
   def __new__(self)
        return Body.__new__(
            self,
            1.28943695621391310e+01,
            -1.51111514016986312e+01,
            -2.23307578892655734e-01,
            2.96460137564761618e-03 * DAYS_PER_YEAR,
            2.37847173959480950e-03 * DAYS_PER_YEAR,
            -2.96589568540237556e-05 * DAYS_PER_YEAR,
            4.36624404335156298e-05 * SOLAR_MASS,
        )


class Neptune(Body)
    def __new__(self)
        return Body.__new__(
            self,
            1.53796971148509165e+01,
            -2.59193146099879641e+01,
            1.79258772950371181e-01,
            2.68067772490389322e-03 * DAYS_PER_YEAR,
            1.62824170038242295e-03 * DAYS_PER_YEAR,
            -9.51592254519715870e-05 * DAYS_PER_YEAR,
            5.15138902046611451e-05 * SOLAR_MASS,
        )


class Sun(Body)
    def __new__(self)
        return Body.__new__(
            self,
            0.0,
            0.0,
            0.0,
            0.0,
            0.0,
            0.0,
            SOLAR_MASS,
        )


class NBodySystem
    def __new__(self, bodies)
        self.bodies = bodies
        px = 0.0
        py = 0.0
        pz = 0.0

        for b in self.bodies
            m = b.mass
            px += b.vx * m
            py += b.vy * m
            pz += b.vz * m

        b = self.bodies[0]
        self.bodies[0] = b.offsetMomentum(px, py, pz)
        return self


    def advance(self, dt):
        dx = 0.0
        dy = 0.0
        dz = 0.0
        distance = 0.0
        mag = 0.0
        size = len(self.bodies)

        for i in range(size)
            bodyi = self.bodies[i]

            for j in range(i + 1, size)
                bodyj = self.bodies[j]
                dx = bodyi.x - bodyj.x
                dy = bodyi.y - bodyj.y
                dz = bodyi.z - bodyj.z

                distance = (dx * dx + dy * dy + dz * dz) ** 0.5
                mag = dt / (distance * distance * distance)

                bodyi.vx -= dx * bodyj.mass * mag
                bodyi.vy -= dy * bodyj.mass * mag
                bodyi.vz -= dz * bodyj.mass * mag

                bodyj.vx += dx * bodyi.mass * mag
                bodyj.vy += dy * bodyi.mass * mag
                bodyj.vz += dz * bodyi.mass * mag

                self.bodies[j] = bodyj

            self.bodies[i] = bodyi

        for i in range(size)
            body = self.bodies[i]
            body.x += dt * body.vx
            body.y += dt * body.vy
            body.z += dt * body.vz
            self.bodies[i] = body


    def energy(self)
        dx = 0.0
        dy = 0.0
        dz = 0.0
        distance = 0.0
        e = 0.0
        size = len(self.bodies)

        for i in range(size)
            bodyi = self.bodies[i]

            e += 0.5 * bodyi.mass * (
                bodyi.vx * bodyi.vx +
                bodyi.vy * bodyi.vy +
                bodyi.vz * bodyi.vz
            )

            for j in range(i + 1, size)
                bodyj = self.bodies[j]
                dx = bodyi.x - bodyj.x
                dy = bodyi.y - bodyj.y
                dz = bodyi.z - bodyj.z

                distance = (dx * dx + dy * dy + dz * dz) ** 0.5
                e -= (bodyi.mass * bodyj.mass) / distance

        return e


bodies = NBodySystem([
    Sun(),
    Jupiter(),
    Saturn(),
    Uranus(),
    Neptune(),
])

n = sys.argv[1]
print('%.9f' % bodies.energy())
for i in range(n) bodies.advance(0.01)
print('%.9f' % bodies.energy())
