import cv2
import mediapipe as mp
import time
import math


class HandDetector:
    def __init__(self, mode=False, maxHands=2, detectionConf=0.5, trackingCon=0.5):
        self.mode = mode
        self.maxHands = maxHands
        self.detectionConf = detectionConf
        self.trackingCon = trackingCon

        self.mpHands = mp.solutions.hands
        self.mpDraw = mp.solutions.drawing_utils
        self.hands = self.mpHands.Hands(self.mode, self.maxHands, self.detectionConf, self.trackingCon)
        self.tipIds = [4, 8, 12, 16, 20]

    def findHands(self, img, draw=True):

        img = cv2.flip(img, 1)
        imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        self.results = self.hands.process(imgRGB)
        self.lms = self.results.multi_hand_landmarks
        # print(results.multi_hand_landmarks)

        if self.lms:
            for hand in self.lms:
                if draw:
                    self.mpDraw.draw_landmarks(img, hand, self.mpHands.HAND_CONNECTIONS)
        return img

    def findPosition(self, img, handNo=0, draw=True):
        xlist = []
        ylist = []
        bbox = []
        self.lmList = []

        if self.lms:
            myhand = self.lms[handNo]
            for id, lm in enumerate(myhand.landmark):
                h, w, c = img.shape
                cx, cy = int(lm.x*w), int(lm.y*h)
                xlist.append(cx)
                ylist.append(cy)
                # print(id, cx, cy)
                self.lmList.append([id, cx, cy])
                if draw:
                    cv2.circle(img, (cx, cy), 5, (255, 0, 10), cv2.FILLED)

            xmin, xmax = min(xlist), max(xlist)
            ymin, ymax = min(ylist), max(ylist)
            bbox = xmin, ymin, xmax, ymax

            if draw:
                cv2.rectangle(img, (bbox[0]-20, bbox[1]-20), (bbox[2]+20, bbox[3]+20), (0, 255, 0), 2)


        return self.lmList, bbox

    def fingersUp(self):
        fingers = []
        # THUMB
        if self.lmList:
            if self.lmList[self.tipIds[0]][1] < self.lmList[self.tipIds[0] - 1][1]:
                fingers.append(1)
            else:
                fingers.append(0)
        # FINGERS
            for id in range(1, 5):
                if self.lmList[self.tipIds[id]][2] < self.lmList[self.tipIds[id] - 2][2]:
                    fingers.append(1)
                else:
                    fingers.append(0)
        return fingers

    def findDistance(self, p1, p2, img, draw=True):

        x1, y1 = self.lmList[p1][1], self.lmList[p1][2]
        x2, y2 = self.lmList[p2][1], self.lmList[p2][2]
        cx, cy = (x2 + x1) // 2, (y1 + y2) // 2
        if draw:
            cv2.circle(img, (x1, y1), 15, (255, 0, 255), cv2.FILLED)
            cv2.circle(img, (x2, y2), 15, (255, 0, 255), cv2.FILLED)
            cv2.line(img, (x1, y1), (x2, y2), (255, 0, 255), 3)
            cv2.circle(img, (cx, cy), 15, (255, 0, 255), cv2.FILLED)

        length = math.hypot(x2 - x1, y2 - y1)
        return length, img, [x1, y1, x2, y2, cx, cy]



def main():
    cTime = 0
    pTime = 0
    detector = HandDetector()
    cap = cv2.VideoCapture(0)
    cap.set(3, 640)
    cap.set(4, 480)
    while cap.isOpened():

        ret, img = cap.read()
        cTime = time.time()
        fps = 1/(cTime-pTime)
        pTime = cTime
        img = detector.findHands(img)
        Clist = detector.findPosition(img)
        if len(Clist) != 0:
            print(Clist[12])
        cv2.putText(img, str(int(fps)),(10, 70) ,cv2.FONT_HERSHEY_COMPLEX, 3, (22, 45, 255), 3 )


        cv2.imshow('Img', img)
        cv2.waitKey(1)


if __name__ == '__main__':
    main()
