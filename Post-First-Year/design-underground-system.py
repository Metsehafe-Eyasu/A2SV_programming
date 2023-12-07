class UndergroundSystem:

    def __init__(self):
        self.check_in_stations = {}
        self.check_out_stations = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.check_in_stations[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        in_station, in_t = self.check_in_stations[id]
        self.check_in_stations.pop(id)
        route = in_station + "_" + stationName
        if route not in self.check_out_stations:
            self.check_out_stations[route] = [0, 0]
        self.check_out_stations[route][0] += t - in_t
        self.check_out_stations[route][1] += 1

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        route = startStation + "_" + endStation
        total = self.check_out_stations[route]
        return total[0] / total[1]


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)